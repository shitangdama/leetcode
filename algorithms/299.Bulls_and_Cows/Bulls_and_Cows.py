<<<<<<< HEAD
def getHint(self, secret, guess):
"""
:type secret: str
:type guess: str
:rtype: str
"""
secret_map, guess_map = {}, {}
bull_count, cow_count = 0, 0
for i in range(len(secret)):
    if secret[i] == guess[i]:
        bull_count += 1
    else:
        if secret[i] in secret_map:
            secret_map[secret[i]] += 1
        else:
            secret_map[secret[i]] = 1
        if guess[i] in guess_map:
            guess_map[guess[i]] += 1
        else:
            guess_map[guess[i]] = 1
for i in guess_map:
    if i in secret_map:
        cow_count += min(secret_map[i], guess_map[i])
return '%sA%sB' % (bull_count, cow_count)
=======
def getHint(self, secret, guess):
"""
:type secret: str
:type guess: str
:rtype: str
"""
secret_map, guess_map = {}, {}
bull_count, cow_count = 0, 0
for i in range(len(secret)):
    if secret[i] == guess[i]:
        bull_count += 1
    else:
        if secret[i] in secret_map:
            secret_map[secret[i]] += 1
        else:
            secret_map[secret[i]] = 1
        if guess[i] in guess_map:
            guess_map[guess[i]] += 1
        else:
            guess_map[guess[i]] = 1
for i in guess_map:
    if i in secret_map:
        cow_count += min(secret_map[i], guess_map[i])
return '%sA%sB' % (bull_count, cow_count)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
