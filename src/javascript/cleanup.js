const Globals = require('./globals')
const Bindings = require('./bindings')

process.on('exit', () => {
	for (const device of Globals.uinputDevices) {
		device.destroy()
	}

	Bindings.global_cleanup()
})
