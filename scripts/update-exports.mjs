import Fs from 'node:fs/promises'
import Path from 'node:path'
import { fileURLToPath } from 'url'

const rootDir = Path.resolve(Path.dirname(fileURLToPath(import.meta.url)), '..')
process.chdir(rootDir)

await Fs.copyFile('package.json', 'package.json~')
const pkg = JSON.parse(await Fs.readFile('package.json', 'utf8'))

pkg.exports = {}

const recurse = async (dirPath) => {
	const files = await Fs.opendir(dirPath)
	for await (const entry of files) {
		if (entry.name.startsWith('_')) { continue }

		if (entry.isDirectory()) {
			if (false
				|| entry.name === 'node_modules'
				|| entry.name === 'testing'
			) { continue }

			await recurse(Path.join(dirPath, entry.name))
		} else {
			if (false
				|| !entry.name.endsWith('.js')
				|| entry.name.endsWith('.test.js')
				|| entry.name.startsWith('_')
			) { continue }

			const filePath = `./${Path.join(dirPath, entry.name)}`

			const key = filePath === './src/index.js' ? '.'
				: `./${filePath.endsWith('/index.js')
					? filePath.slice(6, -9)
					: filePath.slice(6, -3)}`
			pkg.exports[key] = filePath
		}
	}
}

await recurse('.')
await Fs.writeFile('package.json', `${JSON.stringify(pkg, null, 2)}\n`)
