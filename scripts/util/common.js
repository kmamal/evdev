const Fs = require('fs')
const Path = require('path')

const dir = {}
dir.root = Path.join(__dirname, '../..')
dir.libevdev = Path.join(dir.root, 'libevdev')
dir.build = Path.join(dir.root, 'build')
dir.dist = Path.join(dir.root, 'dist')
dir.publish = Path.join(dir.root, 'publish')

const pkgPath = Path.join(dir.root, 'package.json')
const pkg = JSON.parse(Fs.readFileSync(pkgPath).toString())
const version = pkg.version
const isPrerelease = version.includes('-')
const [ , owner, repo ] = pkg.repository.url.match(/([^/:]+)\/([^/]+).git$/u)

const { platform, arch } = process
const targetArch = process.env.CROSS_COMPILE_ARCH || arch
const assetName = `evdev.node-v${version}-${platform}-${targetArch}.tar.gz`

const libevdev = pkg.libevdev
libevdev.assetName = `libevdev-v${libevdev.version}-${platform}-${targetArch}.tar.gz`

module.exports = {
	dir,
	version,
	isPrerelease,
	owner,
	repo,
	platform,
	arch,
	targetArch,
	assetName,
	libevdev,
}
