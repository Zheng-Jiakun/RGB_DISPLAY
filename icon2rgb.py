from PIL import Image
import numpy as np
im = Image.open("./chrome.bmp")
p = np.array(im)

print(p)