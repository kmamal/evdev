const Bindings = require('../bindings')

class UinputDevice {
	constructor (options) {
		const result = Bindings.uinput_createDevice(options)

		this._fd = result.fd
		this._syspath = result.syspath
		this._devnode = result.devnode
	}

	get fd () { return this._fd }
	get syspath () { return this._syspath }
	get devnode () { return this._devnode }

	writeEvents (events) { Bindings.uinput_writeEvents(this._fd, events) }

	destroy () { Bindings.uinput_destroyDevice(this._fd) }
}

module.exports = { UinputDevice }
