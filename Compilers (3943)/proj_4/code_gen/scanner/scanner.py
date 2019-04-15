'''
Jake Goldstein
jsg525
N18131294
CS-UY 3943 Compiler Design & Construction
Spring 2018
Prof. Boris Aronov
...I didn't make this file...
'''

import sys
sys.path.insert(0, '../helpers/helpers')
from helpers.helpers import make_file_name
# This is scanner.py that was given just as a funciton
import tok1


def scanner(input_file):
  # Give the lexer some input
  with open(input_file, 'r') as inf:
      tok1.lexer.input(inf.read(-1))
  # lexer.input(data)

  output_file = make_file_name(input_file, 'scanner')
  with open(output_file,'w') as f:
    f.write("token\t" +  "token\t" + "token\n")
    f.write("number\t" + "name\t"   + "value\n")
  # Tokenize

  # print "token\t" +  "token\t" + "token"

  while True:
      tok = tok1.lexer.token()
      if not tok: 
        # print "FOUND EOF" 
        break      # No more input
      tok.lexpos = tok1.token_dictionary[tok.type]
      with open(output_file,'a') as f:
        f.write(str(tok.lexpos) + '\t\t' + str(tok.type) + '\t\t' + '"'+str(tok.value)+'"' + '\n') 

      # print str(tok.lexpos) + '\t' + str(tok.type) + '\t' + '"'+str(tok.value)+'"'
