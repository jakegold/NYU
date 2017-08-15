import socket

HOST = "gnarlygno.me"
PORT = 8888

def quickMath(num, base):
        if base == "10": 
                return num
        elif base == "2":
                return bin(int(num))
        elif base == "8":
                return oct(int(num))
        elif base == "16":
                return hex(int(num))
        return "-1"
        
def online():
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((HOST, PORT))
        info = s.recv(4048)
        decoder = info.decode("utf-8") 
        print(decoder)
        while True:
                info = s.recv(1024)
                print(info)
                decoder = info.decode("utf-8")
                if(decoder.find("Convert") >= 0):
                        line = decoder.split()
                        num = line[1]
                        num = num[1:]
                        num = num[:-1]
                        base = line[7]
                        base = base[1:]
                        base = base[:-1]
                        result = quickMath(num, base)
                        s.send((result+"\n").encode("utf-8"))
                else:
                        if(decoder.find("spell") >= 0):
                                s.send("Salsaman\n".encode("utf-8"))
                                info = s.recv(4048)
                                print(info)
                                break
        s.close()
        
def main():
        online()
        
if __name__ == "__main__":
        main()
