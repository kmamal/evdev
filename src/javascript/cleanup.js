const Bindings = require('./bindings')

process.on('exit', (code) => {
	if (code !== 0) { return }

	// TODO

	Bindings.global_cleanup()
})
