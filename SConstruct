import os

env = Environment()

env.Append(CCFLAGS = ['-std=c++11', '-O0', '-ggdb'])
env.Append(VERBOSE = ARGUMENTS.get('verbose', 0))
env.Append(LIBPATH=['/usr/lib64', '/usr/lib/x86_64-linux-gnu', '#lib', '#src/3rd/cChord', '#build/src/dht', '#src/3rd/pmemkv/bin'])
# loads shared library from the binary directory 
env.Append(LINKFLAGS ='-Wl,-rpath=.')

# to not trash src folder
VariantDir('build', 'src', duplicate=0)
SConscript('build/SConscript', exports=['env',])

# copy products to bin directory
instDragon = env.Install('bin', 'dragon')
instDragonTest = env.Install('bin', 'dragonTest')
env.Alias('install', [instDragon, instDragonTest])
Depends('install', 'build')

if not GetOption("clean"):
	RequiredLibs = ['boost_system', 'boost_program_options', 'boost_filesystem', 'boost_unit_test_framework',
				'pthread', 'rt', 'dl']

	config = Configure(env)
	for required_lib in RequiredLibs:
		if not config.CheckLib(required_lib):
			config.Finish()
			exit(1)
