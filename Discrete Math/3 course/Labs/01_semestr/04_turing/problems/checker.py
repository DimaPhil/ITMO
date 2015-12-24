import sys

input = open(sys.argv[1], 'r')
output = open(sys.argv[2], 'r')

tokens = input.readline().split()
blankstr = "_" * len(tokens)
tokens += blankstr

initial = {}
base_commands = ['start', 'accept', 'reject', 'blank']
for base_command in base_commands:
    line = output.readline().strip()
    parts = line.split(' ')
    initial[base_command] = parts[1]
commands = output.readlines()
go = {}
for command in commands:
    (now_state, now_symbol, _, new_state, new_symbol, turn) = command.strip().split()
    if now_state not in go:
        go[now_state] = {}
    go[now_state][now_symbol] = [new_state, new_symbol, turn]
position = 0
now_state = initial['start']
while True:
    c = '_'
    if 0 <= position < len(tokens):
        c = tokens[position]
    print('Current state, symbol: %s, %s. Line = %s' % (now_state, c, tokens))
    if c not in go[now_state]:
        message = "Can't go. Now state: %s, symbol: %s" % (now_state, c)
        raise AssertionError(message)
    new_state = go[now_state][c][0]
    new_c = go[now_state][c][1]
    turn = go[now_state][c][2]
    if 0 <= position < len(tokens):
        tokens[position] = new_c
    if new_state == initial['accept']:
        print('Finished, position = %d, line = %s' % (position, tokens))
        break
    now_state = new_state
    if turn == '>':
        position += 1
    if turn == '<':
        position -= 1