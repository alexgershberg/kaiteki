#!/usr/bin/env python3

import os
import sys
import subprocess

if len(sys.argv) <= 1:
    print("usage: c [file.c / file.cpp]")
    exit()


name, ext = os.path.splitext(sys.argv[1])

if ext not in [".c", ".cpp"]:
    print("Error. Invalid file extension.")
    print("Allowed file extensions: .c .cpp")
    exit()


# Compile
subprocess.run(["clang++", "-std=c++20", f"{name + ext}", "-o", name])

# Run
subprocess.run([f"./name"])

# Delete
subprocess.run(["rm", name])

