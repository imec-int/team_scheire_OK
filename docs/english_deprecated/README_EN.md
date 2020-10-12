# TeamScheire: Interactive, immersive operating room

![](./docs/images/scheire.jpg)

&copy; Canvas 2020


## Project description

[Team Scheire](https://www.canvas.be/team-scheire) is a TV show produced by [Canvas](https://www.canvas.be/) in which a team of makers tries to address relevant challenges. Each maker relies on their unique competences to create and 'hack' a solution.

For the second season of the show, [imec](https://www.imec-int.com/en) was contacted by the ZNA Queen Paola Children's Hospital. Debby Callaert, driving force behind the idea, and the rest of the pediatric team asked imec to help them __reduce pre-operative and anaesthetic anxiety among children.__ 
Children that need to have surgery often have little control over their situation and are placed out of their trusted environment. This may cause anxiety and trigger a [fight-or-flight response](https://en.wikipedia.org/wiki/Fight-or-flight_response). This may both obstruct the sedation process and lead to a longer post-operative On the one hand, the children that demonstrate fight and flight responses can obstruct the sedation process. On the other hand any child that experiences pre-operative anxiety can have a longer post-operative recovery (i.e. due to trauma). Reducing anxiety in the operating room therefore is very valuable to the child.

**Distraction** is a technique that has already proven useful in hospital settings, as illustrated by earlier experiments with Virtual Reality and tablets. In the OR, the rules surrounding the introduction of (new) technologies are very strict, and attention has to be paid to respecting the 1.5 meter patient zone. 
Lynn Coorevits's user research indicated that most of the anxiety in children can be attributed to the emptiness of the operating room and the anaesthetic mask. This helped direct the solution towards an immersive experience in which doctors, children and parents can interact with both each other and the environment.

Disclaimer: the solution proposed is **one of many** possible solutions. Alternative approaches can certainly be dreamed up!

### The immersive environment

To create the immersive environment, we made use of projection techniques. Before entering surgery, children were asked to choose between two settings: space or the ocean. In each of these settings, children could perform certain actions that impacted the projected world around them (e.g. blowing into the anaesthetic mask causes a treasure chest to open). This way, **desirable behavior is encouraged and directed through the immersive environment**.


### The props

In a typical surgery, children will only be introduced to the anaesthetic mask in the operating room itself. This approach, however, opted for introducing the mask **before entering the operatig room**. The children were encouraged to choose their preffered setting (space or ocean world) and to decorate their mask accordingly with themed stickers. By having them choose their props in advance, the stressful transition to the operating room could be mitigated and the mask-induced anxiety reduced. 

To ensure thematic continuity along the way, the stickers were designed using the same Unity assets used to build the virtual environments.
 
Because kids get to choose their props in advance, the transition to the Operations Room runs a lot smoother. Plus, they are less afraid of the mask being handed to them, as they had the chance to familiarize themselves with it. The props in this case where a range of stickers, in either the water- or space theme, which kids can use to add to their mask. 

1. Git installeren
1. [Fysieke opstelling](markdown_files/fysieke_opstelling.md)
2. [Hardware setup](markdown_files/hardware_NL.md)
3. [Software: video projection](markdown_files/software_video_map_NL.md)
4. [Software: video creation](markdown_files/software_video_creation_NL.md)
5. [stickers](markdown_files/stickers.md)


### License references

This project is made with a few different software applications and frameworks. Here we'll list them and list their respective licenses if needed:

1. [Unity license](https://unity3d.com/legal/as_terms)
2. [OpenFrameworks (MIT License)](https://openframeworks.cc/about/license/) Libraries:
	3. [ofxAruco: BSD License](https://github.com/arturoc/ofxAruco)
	5. [ofxCV: MIT license](https://github.com/kylemcdonald/ofxCv)
	7. [ofxHapPlayer: custom license](https://github.com/bangnoise/ofxHapPlayer/blob/master/LICENSE)
8. [Raspberry pi documentation: creative commons license](https://www.raspberrypi.org/documentation/)
