#!/usr/bin/env python

import inspect
import os
import math
import array
import sys
import platform
from subprocess import call, Popen, PIPE, STDOUT

#
# Call this script with the install directory
# tests directory on the command line
#
def test_vs30_query(dir):
    # Basic vs30 test.
    os.chdir(dir)

    vs30_query_call = "../bin/vs30_query"
    if platform.system() == "Darwin" :
       myproc = Popen(["../utilities/call_install_name_tool", "../bin/vs30_query"], stdout=PIPE, stderr=STDOUT)
       myoutput = myproc.communicate()
       vs30_query_call = "../utilities/run_vs30_query.sh"

    proc = Popen([vs30_query_call, "-f", "../conf/ucvm.conf", "-m", "bbp1d", \
                  "-i", "0.1"], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    output = proc.communicate(input=b"-118 34\n-117 35")[0]
    
## OLD one    expected_output = b" -118.0000    34.0000    777.764\n -117.0000    35.0000    777.764\n"
    expected_output = b" -118.0000    34.0000    399.698\n -117.0000    35.0000    399.698\n"
    
    if not output == expected_output:
        print("Error: Vs30 expected output not equal to actual output.\n")
        print("Expected output:\n%s\n\nActual output:\n%s\n" % (expected_output, output))
        return 1
    
    return 0

def test_ssh_generate(dir):
    # Basic small-scale heterogeneities validation.
    # writes result to install/tests directory
    os.chdir(dir)

    ssh_generate_call = "../bin/ssh_generate"
    if platform.system() == "Darwin" :
       myproc = Popen(["../utilities/call_install_name_tool", "../bin/ssh_generate"], stdout=PIPE, stderr=STDOUT)
       myoutput = myproc.communicate()
       ssh_generate_call = "../utilities/run_ssh_generate.sh"

    proc = Popen([ssh_generate_call, "-u", "0.1", "-d", "20", "-l", "50", \
                  "-s", "5", "-a", "100", "-b", "100", "-c", "100", \
                  "-f", "inputs/floats.in", "-x", "inputs/floats_complex.in", \
                  "-m", "ssh_generate.out"], \
                  stdout=PIPE, stdin=PIPE, stderr=STDOUT)    
    output = proc.communicate()

    f = open("./ssh_generate.out", "rb")
    generatedfloats = array.array("f")
    generatedfloats.fromfile(f, 100 * 100 * 100)
    f.close()
    
    os.remove("./ssh_generate.out")
    
    f = open("./ref/ssh_generate_floats.ref", "rb")
    validfloats = array.array("f")
    validfloats.fromfile(f, 100 * 100 * 100)
    f.close()
    
    for i in range(0, len(generatedfloats)):
        if not generatedfloats[i] == validfloats[i]:
            return 1
    
    return 0

# Main loop.
if __name__ == "__main__":
    func_list = [x for x in dir(__import__(inspect.getmodulename(__file__))) if "test_" in x]

    passed = 1

    sys.path.append("../conf/")
    from ucvm_env import *
    setup_ucvm_env()

    for func in func_list:
        print("Runnning test %s" % func)
    
        if eval("%s('%s')" % (func, sys.argv[1])) == 0:
            print("[SUCCESS]")
        else:
            passed = 0
            print("[FAIL]")
    
    if not passed:
        print("Some tests failed. Please try re-compiling UCVM. If that doesn't work")
        print("please contact software@scec.org.")
