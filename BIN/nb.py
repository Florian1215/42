import random
import pyperclip
import os

res = ' '.join([str(nb) for nb in random.sample(range(-500, 500), k=50)])
pyperclip.copy(res)
os.system(f'./push_swap {res}')