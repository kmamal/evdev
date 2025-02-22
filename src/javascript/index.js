const { isMainThread } = require('worker_threads')
if (!isMainThread) { throw new Error('@kmamal/evdev can only be used in the main thread') }

try {
	const Bindings = require('./bindings')
	const Enums = require('./enums')

	const info = Bindings.global_initialize()

	const { uinput } = require('./uinput')

	require('./cleanup')

	module.exports = {
		...Enums,
		info,
		uinput,
	}
} catch (err) {
	console.warn(err)
	console.warn("@kmamal/evdev is not available on this platform")
	module.exports = null
}
