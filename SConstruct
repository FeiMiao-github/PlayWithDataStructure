import scons_compiledb

class CONFIG:
    DEBUG = 0
    RELEASE = 1

type = CONFIG.DEBUG

if type == CONFIG.DEBUG:
    env = Environment(CPPFLAGS="-g -Wall -O2")
else:
    env = Environment(CPPFLAGS="-O3")

env['CPPFLAGS'] += ' -std=c++23'

scons_compiledb.enable(env)

Export('env')

env.VariantDir('build', 'src', duplicate=0)
env.SConscript('build/SConscript')
env.CompileDb()


