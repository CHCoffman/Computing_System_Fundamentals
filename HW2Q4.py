import random

from random import choices

random.seed()

print(random.randrange(99))

print(random.uniform(0.25,0.5))

thirdRandNum = random.uniform(3,4)

nums = [1, 2, thirdRandNum]
probs = [0.5, 0.2, 0.3]

print(choices(nums, probs))