from cgi import test
import random
import subprocess
import sys
import os

amount = 5
test = 100
res = []

if len(sys.argv) > 1:
	amount = int(sys.argv[1])

dirname = os.path.dirname(os.path.abspath(__file__))
push = os.path.join(dirname, "push_swap")
for i in range(test):
	nums = random.sample(range(-2147483648, +2147483647), amount)
	args = [str(num) for num in nums]
	out = [push] + args
	ou = subprocess.check_output(out, stderr=subprocess.STDOUT, timeout=5).splitlines()
	res.append(len(ou))
#print average
print(sum(res) / len(res))
