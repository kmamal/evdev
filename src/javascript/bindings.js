const Path = require('path')

const path = Path.resolve(__dirname, '../../dist/evdev.node')

module.exports = require(path)
