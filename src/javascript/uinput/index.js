const { UinputDevice } = require('./device')

module.exports = {
	createDevice (options) { return new UinputDevice(options) },
}
