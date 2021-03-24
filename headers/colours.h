/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:37:29 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 14:58:46 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
# define COLOURS_H

typedef struct		s_argb
{
	int				a;
	int				r;
	int				g;
	int				b;
}					t_argb;

enum				e_colour {
	lightpink = 0xffb6c1,
	pink = 0xffc0cb,
	crimson = 0xdc143c,
	lavenderblush = 0xfff0f5,
	palevioletred = 0xdb7093,
	hotpink = 0xff69b4,
	deeppink = 0xff1493,
	mediumvioletred = 0xc71585,
	orchid = 0xda70d6,
	thistle = 0xd8bfd8,
	plum = 0xdda0dd,
	violet = 0xee82ee,
	fuchsia = 0xff00ff,
	darkmagenta = 0x8b008b,
	purple = 0x800080,
	mediumorchid = 0xba55d3,
	darkviolet = 0x9400d3,
	darkorchid = 0x9932cc,
	indigo = 0x4b0082,
	blueviolet = 0x8a2be2,
	mediumpurple = 0x9370db,
	mediumslateblue = 0x7b68ee,
	slateblue = 0x6a5acd,
	darkslateblue = 0x483d8b,
	ghostwhite = 0xf8f8ff,
	lavender = 0xe6e6fa,
	blue = 0x0000ff,
	mediumblue = 0x0000cd,
	darkblue = 0x00008b,
	navy = 0x000080,
	midnightblue = 0x191970,
	royalblue = 0x4169e1,
	cornflowerblue = 0x6495ed,
	lightsteelblue = 0xb0c4de,
	lightslategray = 0x778899,
	slategray = 0x708090,
	dodgerblue = 0x1e90ff,
	aliceblue = 0xf0f8ff,
	steelblue = 0x4682b4,
	lightskyblue = 0x87cefa,
	skyblue = 0x87ceeb,
	deepskyblue = 0x00bfff,
	lightblue = 0xadd8e6,
	powderblue = 0xb0e0e6,
	cadetblue = 0x5f9ea0,
	darkturquoise = 0x00ced1,
	azure = 0xf0ffff,
	lightcyan = 0xe0ffff,
	paleturquoise = 0xafeeee,
	aqua = 0x00ffff,
	darkcyan = 0x008b8b,
	teal = 0x008080,
	darkslategray = 0x2f4f4f,
	mediumturquoise = 0x48d1cc,
	lightseagreen = 0x20b2aa,
	turquoise = 0x40e0d0,
	aquamarine = 0x7fffd4,
	mediumaquamarine = 0x66cdaa,
	mediumspringgreen = 0x00fa9a,
	mintcream = 0xf5fffa,
	springgreen = 0x00ff7f,
	mediumseagreen = 0x3cb371,
	seagreen = 0x2e8b57,
	honeydew = 0xf0fff0,
	darkseagreen = 0x8fbc8f,
	palegreen = 0x98fb98,
	lightgreen = 0x90ee90,
	limegreen = 0x32cd32,
	lime = 0x00ff00,
	forestgreen = 0x228b22,
	green = 0x008000,
	darkgreen = 0x006400,
	lawngreen = 0x7cfc00,
	chartreuse = 0x7fff00,
	greenyellow = 0xadff2f,
	darkolivegreen = 0x556b2f,
	yellowgreen = 0x9acd32,
	olivedrab = 0x6b8e23,
	ivory = 0xfffff0,
	beige = 0xf5f5dc,
	lightyellow = 0xffffe0,
	lightgoldenrodyellow = 0xfafad2,
	yellow = 0xffff00,
	olive = 0x808000,
	darkkhaki = 0xbdb76b,
	palegoldenrod = 0xeee8aa,
	lemonchiffon = 0xfffacd,
	khaki = 0xf0e68c,
	gold = 0xffd700,
	cornsilk = 0xfff8dc,
	goldenrod = 0xdaa520,
	darkgoldenrod = 0xb8860b,
	floralwhite = 0xfffaf0,
	oldlace = 0xfdf5e6,
	wheat = 0xf5deb3,
	orange = 0xffa500,
	moccasin = 0xffe4b5,
	papayawhip = 0xffefd5,
	blanchedalmond = 0xffebcd,
	navajowhite = 0xffdead,
	antiquewhite = 0xfaebd7,
	c_tan = 0xd2b48c,
	burlywood = 0xdeb887,
	darkorange = 0xff8c00,
	bisque = 0xffe4c4,
	linen = 0xfaf0e6,
	peru = 0xcd853f,
	peachpuff = 0xffdab9,
	sandybrown = 0xf4a460,
	chocolate = 0xd2691e,
	saddlebrown = 0x8b4513,
	seashell = 0xfff5ee,
	sienna = 0xa0522d,
	lightsalmon = 0xffa07a,
	coral = 0xff7f50,
	orangered = 0xff4500,
	darksalmon = 0xe9967a,
	tomato = 0xff6347,
	salmon = 0xfa8072,
	mistyrose = 0xffe4e1,
	lightcoral = 0xf08080,
	snow = 0xfffafa,
	rosybrown = 0xbc8f8f,
	indianred = 0xcd5c5c,
	red = 0xff0000,
	brown = 0xa52a2a,
	firebrick = 0xb22222,
	darkred = 0x8b0000,
	maroon = 0x800000,
	white = 0xffffff,
	whitesmoke = 0xf5f5f5,
	gainsboro = 0xdcdcdc,
	lightgrey = 0xd3d3d3,
	silver = 0xc0c0c0,
	darkgray = 0xa9a9a9,
	gray = 0x808080,
	dimgray = 0x696969,
	black = 0x000000
};

t_argb			int2argb(int color);

#endif
