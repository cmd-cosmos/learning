# pylint:skip-file
# type:ignore

import pygame
import sys  

pygame.init()

WIDTH, HEIGHT = 800,600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("basic window")

clock = pygame.time.Clock()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    screen.fill((0,0,255))
    pygame.display.flip()
    clock.tick(60) # 60 fps

pygame.quit()
sys.exit()