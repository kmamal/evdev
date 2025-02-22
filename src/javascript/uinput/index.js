const Globals = require('../globals')
const { UinputDevice } = require('./device')

const uinput = {
	get devices () { return [ ...Globals.uinputDevices.values() ] },

	createDevice (options) { return new UinputDevice(options) },
}

module.exports = { uinput }
