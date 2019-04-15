table1 = [
    ['if', 2, 'keyword-if'],
    ['else', 3, 'keyword-else'],
    ['while', 4, 'keyword-while'],
    ['\(', 15, 'left-par'],
    ['\)', 16, 'right-par'],
    ['[0-9]+', 23, 'integer-literal'],
    ['==', 34, 'equal'],
    ['[a-zA-Z][a-zA-Z0-9]*', 49, 'ID'],
    ['[ \t]', 99, 'WS'],
    ['\n', 100, 'newline'],
    ['', 101, 'end-of-file']
]


table2 = [
    ['if', 1, 'if'],
    ['while', 2, 'while'],
    ['else', 3, 'else'],
    ['case', 4, 'case'],
    ['switch', 5, 'switch'],
    ['[a-zA-Z_][a-zA-Z_0-9]*', 10, 'ID'],
    ['\+|-|\*|\/|\^|~|=|==|<=|=>|\+=|-=|\*=|\/=|!=', 11, 'op'],
    ['\(', 15, 'LAPR'],
    ['\)', 16, 'RAPR'],
    ['\[', 17, 'LBR'],
    ['\]', 18, 'RBR'],
    ['\{', 19, 'LBRC'],
    ['\}', 20, 'RBRC'],
    ['[1-9][0-9]*|0x[0-9A-F]+|0[0-7]*', 23, 'int'],
    ['[0-9]*(\.[0-9]|[0-9]\.)[0-9]*', 24, 'fixed'],
    ['[ \t]', 99, 'WS'],
    ['\n', 100, 'newline'],
    ['', 101, 'end-of-file']
]


table3 = [
    ["[^() \t']+", 1, 'atom'],
    ["'", 2, 'quote'],
    ['"[^"\n]*"', 3, 'string'],
    ['\(', 15, 'LPAR'],
    ['\)', 16, 'RPAR'],
    ['[ \t]', 99, 'WS'],
    ['\n', 100, 'newline'],
    ['', 101, 'end-of-file']
]


table4 = [
    ['int', 1, 'int'],
    ['float', 2, 'float'],
    ['if', 3, 'if'],
    ['else', 4, 'else'],
    ['while', 5, 'while'],
    ['return', 6, 'return'],
    ['read', 7, 'read'],
    ['write', 8, 'write'],
    ['[a-zA-Z_][a-zA-Z_0-9]*', 10, 'ID'],
    ['\+|-|\*|\/|=', 11, 'op'],
    ['\(', 15, 'LPAR'],
    ['\)', 16, 'RPAR'],
    ['\{', 19, 'LBRACE'],
    ['\}', 20, 'RBRACE'],
    [';', 21, 'semi'],
    [',', 22, 'comma'],
    ['[0-9]+', 23, 'int'],
    ['[0-9]+\.[0-9]+', 24, 'float'],
    ['[ \t]', 99, 'WS'],
    ['\n', 100, 'newline'],
    ['', 101, 'end-of-file']
]
