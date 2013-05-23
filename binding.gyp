{
	'targets': [
		{
			'target_name': 'MyExtension',
			'sources': [
				'src/ExtensionMain.cpp',
				'src/MyExtension.cpp',
				'src/MyExtension.h',
			],
			'include_dirs': [
				'<(module_root_dir)/src/',
			]			
		}
	]
}