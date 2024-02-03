import Fs from 'node:fs'
import Path from 'node:path'
import { execSync } from 'node:child_process'
import C from './util/common.js'

await Promise.all([
	C.dir.build,
	C.dir.dist,
	C.dir.publish,
].map(async (dir) => {
	await Fs.promises.rm(dir, { recursive: true }).catch(() => {})
}))

console.log("build in", C.dir.build)
const LIBEVDEV_INC = Path.join(C.dir.libevdev, 'include')
const LIBEVDEV_LIB = Path.join(C.dir.libevdev, 'lib')

let archFlag = ''
if (process.env.CROSS_COMPILE_ARCH) {
	archFlag = `--arch ${process.env.CROSS_COMPILE_ARCH}`
}

process.chdir(C.dir.root)
execSync(`npx -y node-gyp rebuild ${archFlag} -j max --verbose`, {
	stdio: 'inherit',
	env: {
		...process.env,
		LIBEVDEV_INC,
		LIBEVDEV_LIB,
	},
})

console.log("install to", C.dir.dist)
await Fs.promises.rm(C.dir.dist, { recursive: true }).catch(() => {})
await Fs.promises.mkdir(C.dir.dist, { recursive: true })

await Promise.all([
	Fs.promises.cp(
		Path.join(C.dir.build, 'Release/evdev.node'),
		Path.join(C.dir.dist, 'evdev.node'),
	),
	(async () => {
		const libs = await Fs.promises.readdir(LIBEVDEV_LIB)
		await Promise.all(libs.map(async (name) => {
			await Fs.promises.cp(
				Path.join(LIBEVDEV_LIB, name),
				Path.join(C.dir.dist, name),
				{ verbatimSymlinks: true },
			)
		}))
	})(),
])
