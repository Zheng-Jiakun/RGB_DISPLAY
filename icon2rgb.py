from PIL import Image
import numpy as np
out = []
im = Image.open("./chrome.bmp")
im_rgb = im.convert("RGB")

for [r,g,b] in iter(im_rgb.getdata()):
    # print "a" + "b"
    print ("{" + str(r) + "," + str(g) +", "+str(b)+"}")
    # out.append(out)
    # print pix

p = np.array(im)
print out

# print(p)