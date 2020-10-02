
#inventory = open("inventory.csv", "r+")  # 'r' is used to read the file
#infoFile = inventory.readlines()
lineNum = 1
inventory = open("ochem.txt", "r+")  # 'r+' is used to read and write in the file

charList = ["AA", "AT", "AG", "AC", "TA", "TT", "TG", "TC","GA", "GT", "GG", "GC", "CA", "CT", "CG", "CC"]
freqList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for line in inventory:
  
  if ( ( lineNum == 1) or (lineNum == 2)):
    lineNum += 1
  else:
    rowList = line.split(" ")  # splits line and creates list
    a = " "
    letterList = list (rowList[4] )

    for i in range( len(letterList) - 1 ):
      twoLetters = letterList[i] + letterList[i + 1]
      index = charList.index(twoLetters)
      freqList [index] = freqList[index] + 1

print(freqList)

max = 0
index = 0
for i in range(len(freqList)):
  if (max < freqList[i]):
    max = freqList[i]
    index = i

print(charList[index])
print(freqList[index])
