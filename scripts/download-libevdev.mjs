import Fs from 'node:fs'
import { once } from 'node:events'
import C from './util/common.js'
import { fetch } from './util/fetch.js'
import Tar from 'tar'

const url = `https://github.com/${C.libevdev.owner}/${C.libevdev.repo}/releases/download/v${C.libevdev.version}/${C.libevdev.assetName}`

console.log("fetch", url)
const response = await fetch(url)

console.log("unpack to", C.dir.libevdev)
await Fs.promises.rm(C.dir.libevdev, { recursive: true }).catch(() => {})
await Fs.promises.mkdir(C.dir.libevdev, { recursive: true })
const tar = Tar.extract({ gzip: true, C: C.dir.libevdev })
response.stream().pipe(tar)
await once(tar, 'finish')
