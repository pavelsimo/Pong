import csv

IMG_WIDTH = 1024
IMG_HEIGHT = 1024

with open('MainFont_EN.FontDef.csv', 'rb') as csvfile:
    csvreader = csv.reader(csvfile, delimiter=',')
    for row in csvreader:
        ch, left, top, right, bottom = int(row[0]), float(row[1]), float(row[2]), float(row[3]), float(row[4])
        x = left * IMG_WIDTH
        y = top * IMG_HEIGHT
        w = (right * IMG_WIDTH) - x
        h = (bottom * IMG_HEIGHT) - y
        print 'AddCharacter(%s, %s, %s, %s, %s);' % (ch, x, y, w, h)
