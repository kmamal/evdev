
if (!process.env.NODE_EVDEV_FROM_SOURCE) {
	try {
		await import('./download-release.mjs')
		process.exit(0)
	} catch (error) {
		console.log("failed to download release")
	}
} else {
	console.log("skip download and build from source")
}

await import('./download-libevdev.mjs')
await import('./build.mjs')
