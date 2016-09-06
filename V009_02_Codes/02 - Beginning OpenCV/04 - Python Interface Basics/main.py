#!/usr/bin/python
import cv2

cv2.namedWindow("Image")
cv2.namedWindow("Processed Image")

if __name__ == '__main__':
    import sys
    try: image = cv2.imread(sys.argv[1])
    except: image = cv2.imread("lena.jpg")

processedImage = image.copy()

height, width, nColors = processedImage.shape

for y in xrange(height):
    for x in xrange(width):
        B = processedImage.item(y, x, 0)
        G = processedImage.item(y, x, 1)
        R = processedImage.item(y, x, 2)
        processedImage.itemset(y, x, 0, 255 - B)
        processedImage.itemset(y, x, 1, 255 - G)
        processedImage.itemset(y, x, 2, 255 - R)

cv2.imshow("Image", image)
cv2.imshow("Processed Image", processedImage)

cv2.waitKey(0)
cv2.destroyAllWindows()
