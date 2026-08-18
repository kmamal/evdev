import Fs from 'node:fs'
import Stream from 'node:stream'
import C from './util/common.js'
import * as Tar from 'tar'

const url = `https://github.com/${C.libevdev.owner}/${C.libevdev.repo}/releases/download/v${C.libevdev.version}/${C.libevdev.assetName}`

console.log("fetch", url)
const response = await fetch(url)
if (!response.ok) { throw new Error(`bad status code ${response.status}`) }

console.log("unpack to", C.dir.libevdev)
await Fs.promises.rm(C.dir.libevdev, { recursive: true }).catch(() => {})
await Fs.promises.mkdir(C.dir.libevdev, { recursive: true })
await Stream.promises.pipeline(
	Stream.Readable.fromWeb(response.body),
	Tar.extract({ preservePaths: true, gzip: true, C: C.dir.libevdev }),
)
