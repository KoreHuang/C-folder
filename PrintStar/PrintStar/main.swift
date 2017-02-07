//
//  main.swift
//  PrintStar
//
//  Created by mac on 15/8/11.
//  Copyright (c) 2015年 mac. All rights reserved.
//

import Foundation

let lineNum = 9


var spaceNum = lineNum/2+3

var starNum=1

for i in 0...lineNum/2{
    
    spaceNum = lineNum/2+3
    
    for   spaceNum=spaceNum-i;spaceNum>0;spaceNum-- {
        print(" ", terminator: "")
    }
    
    for starNum=1;starNum<=2*i+1;starNum++ {
        print("*", terminator: "")
    }
        print("\n", terminator: "")
}
for i in 1...(lineNum-lineNum/2-1) {
    
    for spaceNum = i-1;spaceNum>0;spaceNum-- {
        print(" ", terminator: "")
    }
    
    for var tamNum=2*(lineNum/2-i+1)-1;tamNum>0;tamNum-- {
        print("*", terminator: "")
    }
    for spaceNum=1;spaceNum<=2*i-1;spaceNum++ {
        print(" ", terminator: "")
    }
    for var tamNum=2*(lineNum/2-i+1)-1;tamNum>0;tamNum-- {
        print("*", terminator: "")
    }
    
    print("\n", terminator: "")

}