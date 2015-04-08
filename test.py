#!/usr/bin/env python

from __future__ import print_function
import helloworld

print("helloworld.talk('')")
print(helloworld.talk(''))
print("helloworld.talk('test')")
print(helloworld.talk('test'))
print("Trying to helloworld.talk()")
try:
    print(helloworld.talk())
except helloworld.error as e:
    print('Failed with error:', e)
