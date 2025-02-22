const Globals = require('./globals')
const Bindings = require('./bindings')

process.on('exit', (code) => {
	if (code !== 0) { return }

	for (const device of Globals.uinputDevices) {
		device.destroy()
	}

	Bindings.global_cleanup()
})
