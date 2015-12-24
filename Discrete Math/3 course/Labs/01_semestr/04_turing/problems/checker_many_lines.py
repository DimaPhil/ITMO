import sys

input = open(sys.argv[1], 'r')
output = open(sys.argv[2], 'r')

tokens = input.readline().split()

number_of_roads = int(output.readline())
commands = output.readlines()
go = {}
for command in commands:
    (now_state, now_symbol, _, new_state, new_symbol, turn) = command.split()
    if now_state not in go:
        go[now_state] = {}
    go[now_state][now_symbol] = [new_state, new_symbol, turn]
position = 0
now_state = 'S'
while True:
    c = '_'
    if 0 <= position < len(tokens):
        c = tokens[position]
    print('Current state, symbol: %s, %s. Line = %s' % (now_state, c, tokens))
    if c not in go[now_state]:
        raise AssertionError("Can't go. Now state: %s, symbol: %s" % (now_state, c))
    new_state = go[now_state][c][0]
    new_c = go[now_state][c][1]
    turn = go[now_state][c][2]
    if 0 <= position < len(tokens):
        tokens[position] = new_c
    if new_state == 'AC':
        print('Finished, line = %s' % tokens)
        break
    now_state = new_state
    if turn == '>':
        position += 1
    if turn == '<':
        position -= 1
