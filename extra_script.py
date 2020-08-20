Import("env")
import shutil

def store_hex(source, target, env):
  shutil.copy(target[0].rstr(), "./output/apprentice-wizard.hex")

env.AddPostAction("$BUILD_DIR/firmware.hex", store_hex);
