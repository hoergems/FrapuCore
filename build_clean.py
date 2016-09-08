import subprocess
import os
import sys

shared_path = os.path.dirname(os.path.abspath(__file__))

cmake_command = "rm -rf * && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/usr/local .."
cmake_commad_abt = "rm -rf * && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_HISTOGRAM_INCLUDE_DIR=/usr/local/include -DHISTOGRAM_LIBRARY_DIRS=/usr/local/lib .."

cmd_build_install = "make -j3 && sudo make install"
cmd_build = "make -j3"
cmd_install = "sudo make install"

urdfreaderPath = shared_path + "/urdfreader/build"
frapuPath = shared_path + "/FrapuCore/build"
robotHeadersPath = shared_path + "/robot_headers/build"
robotsPath = shared_path + "/robots/build"
robotEnvironmentPath = shared_path + "/robot_environment/build"
pathPlannerPath = shared_path + "/path_planner/build"
viewerPath = shared_path + "/viewer_interface/build"
rbdlPath = shared_path + "/rbdl_interface/build"
kalmanPath = shared_path + "/KalmanFilter/build"
abtPath = shared_path + "/abt/src/problems/robot_problem/build"

popen = subprocess.Popen(cmake_command, cwd=urdfreaderPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=urdfreaderPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_command, cwd=rbdlPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=rbdlPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_command, cwd=viewerPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=viewerPath, shell=True)
popen.wait()


popen = subprocess.Popen(cmd_build_install, cwd=kalmanPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_install, cwd=robotHeadersPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_command, cwd=frapuPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=frapuPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_command, cwd=robotsPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=robotsPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_command, cwd=robotEnvironmentPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=robotEnvironmentPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_command, cwd=pathPlannerPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build_install, cwd=pathPlannerPath, shell=True)
popen.wait()

popen = subprocess.Popen(cmake_commad_abt, cwd=abtPath, shell=True)
popen.wait()
popen = subprocess.Popen(cmd_build, cwd=abtPath, shell=True)
popen.wait()


'''for i in xrange(k, k_end):
    popen subprocess.P
    cmd = "tar -zcvf hrf" + str(i) + ".tar.gz LQG" + str(i) + "/"
    popen = subprocess.Popen(cmd, cwd=shared_path, shell=True)
    popen.wait()'''
