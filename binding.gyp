{
	'targets': [{
		'target_name': 'evdev',
		'sources': [
			'src/native/module.cpp',
			'src/native/enums.cpp',
			'src/native/global.cpp',
			'src/native/uinput.cpp',
		],
		'dependencies': [
			"<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except",
		],
		'defines': [
			'NAPI_VERSION=<(napi_build_version)',
			'NODE_ADDON_API_DISABLE_DEPRECATED',
		],
		'conditions': [
			['OS == "linux"', {
				'cflags': [ '-D_REENTRANT' ],
				'cflags_cc': [ '-std=c++17' ],
				'include_dirs': [ '$(LIBEVDEV_INC)' ],
				'libraries': [ '-L$(LIBEVDEV_LIB)', '-levdev' ],
				'link_settings': {
					'libraries': [ "-Wl,-rpath,'$$ORIGIN'" ],
				},
			}],
		],
	}],
}
