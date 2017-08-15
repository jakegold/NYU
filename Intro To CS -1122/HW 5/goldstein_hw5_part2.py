
# Operation code to mnemonic dictionary
# You can use this to lookup the machine code
# and translate it to the mnemonic instruction
codes = {1: "ADD", 2: "SUB", 3: "STA", 5: "LDA", 6: "BRA", 7: "BRZ", 8: "BRP", 901: "INP", 902: "OUT", 000: "HLT"}

def disassemble(operation_code):
    if operation_code > 900:
        print codes[operation_code]
        return
    first = operation_code/100
    if first == 0:
        print codes[first]
    else:
        print codes[first], '', operation_code%100


def main():
    toDo = []
    while True:
        thing = input("What should I do next?, to end data input '000': ")
        if thing == 000:
            break
        elif thing >= 100 and thing < 400:
            toDo.append(thing)
        elif thing > 499 and thing < 900:
            toDo.append(thing)
        elif thing == 901 or thing == 902:
            toDo.append(thing)
        else:
            print "Data not added, please enter a three digit number, or to end data input enter '000'"
    toDo.append(000)
    for thing in toDo:
        disassemble(thing)


if __name__ == "__main__":
    main()
