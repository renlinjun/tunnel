package com.tunnel.message;

import java.util.Random;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/3/9 15:29
 */
public class PlateNumber {

    public static String createNum() {
        String carNum = "";
        Random random=new Random();
        int areaInt = random.nextInt(Constants.area.length-1);
        carNum = Constants.area[areaInt];
        int areaLetterInt = random.nextInt(Constants.letter.length-1);
        carNum = carNum + Constants.letter[areaLetterInt]+" ";
        for(int j=0;j<5;j++) {
            int numStrInt = random.nextInt(Constants.number.length-1);
            carNum = carNum + Constants.number[numStrInt];
        }


        return carNum;
    }
}
