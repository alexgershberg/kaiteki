#!/usr/bin/env python3

import os
import sys
import subprocess

if len(sys.argv) <= 1:
    print("usage: c [file.c / file.cpp]")
    exit(1)


name, ext = os.path.splitext(sys.argv[1])

if ext not in [".c", ".cpp"]:
    print("Error. Invalid file extension.")
    print("Allowed file extensions: .c .cpp")
    exit(1)


# Compile
compile = subprocess.run(["g++", "-std=c++20", f"{name + ext}", "-o", name])
if compile.returncode != 0:
    exit(1)


# Run
run = subprocess.run([f"./{name}"])
print(f"Process finished with exit code {run.returncode}")


# Delete
delete = subprocess.run(["rm", name])
