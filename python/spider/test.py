import tesserocr
from PIL import Image

image = Image.open('/home/qingshenghe/code/python/spider/image.png')
print(tesserocr.image_to_text(image))