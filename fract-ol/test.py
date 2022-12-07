import pygame
import os

width, height = 1920,1080
win = (width, height)
screen = pygame.display.set_mode(win)
xaxis = width/1.80 + 150
yaxis = height/2
scale = 450 
iterations = 50

def main():

	for iy in range(int(height/2+1)):
		for ix in range(width):
			z = 0+0j
			c = complex(float(ix-xaxis)/scale, float(iy-yaxis)/scale)
			x=c.real
			y=c.imag
			y2=y*y
			q=(x-0.25)**2+y2
			if not(q*(q+(x-0.25))<y2/4.0 or (x+1.0)**2 + y2 <0.0625):
				for i in range(iterations):

					z = z**2+c
					if abs(z) > 2:
						v = 765*i/iterations
						if v > 510:
							color = (0X68, 0XB9, 0X84) # INT
						elif v > 255:
							color = (0XCF, 0XFD, 0XE1) # EXT
						else:
							color = (0x2B, 0X3A, 0x55) # BG
						break
					else:
						color = (0xFF, 0x70, 0x00) # FG

			screen.set_at((ix, iy), color)
			screen.set_at((ix, height-iy), color)

	pygame.display.update()
	run = True
	while run:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				run = False
	pygame.quit()

main()
