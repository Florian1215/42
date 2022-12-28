import random
import pyperclip
import os
import sys

res = ' '.join([str(nb) for nb in random.sample(range(-500, 500), k=int(sys.argv[1]) if len(sys.argv) > 2 else 20)])
pyperclip.copy(res)
os.system(f'./push_swap {res}')