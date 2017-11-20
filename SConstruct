import os

env = Environment()

'''
	Compiler flags
'''
env.Append(CCFLAGS=['-std=c++11', '-O0', '-ggdb'])

'''
	Depends on linux distribution
'''
env.Append(LIBPATH=[
	'/usr/lib64',					# Fedora
	'/usr/lib/x86_64-linux-gnu', 	# Ubuntu
	'#third-party/cChord',
	'#third-party/pmemkv/bin', 
	'#build/', 
	])

'''
	Linker options
	- loads shared library from the binary directory
'''
env.Append(LINKFLAGS='-Wl,-rpath=.')

env.Append(VERBOSE=ARGUMENTS.get('verbose', 0))

'''
	Build dependencies first
'''
SConscript('third-party/SConscript', exports='env')

'''
	Build FogKV library (shared, static ones)
	Products will be saved in "build" directory to not trash lib folder
'''
VariantDir('build', 'lib', duplicate=0)
SConscript('build/SConscript', exports=['env', ])


'''
	Build examples
'''
SConscript('examples/SConscript', exports=['env', ])


# SConscript('tests/SConscript', exports=['env', ])

# copy products to bin directory
#instDragon = env.Install('bin', 'examples/node/dragon')
#instDragonTest = env.Install('bin', 'tests/dragonTest')
#env.Alias('install', [instDragon, instDragonTest])

env.Alias('install', '#bin')
Depends('install', 'build')

if not GetOption("clean"):
	RequiredLibs = [
				'boost_system', 
				'boost_program_options', 
				'boost_filesystem', 
				'boost_unit_test_framework',
				'pthread', 
				'rt', 
				'dl',
				'log4cxx'
				]

	config = Configure(env)
	for required_lib in RequiredLibs:
		if not config.CheckLib(required_lib):
			config.Finish()
			exit(1)
	config.Finish()