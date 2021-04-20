package model;

public class ScheduleModel {

    public native void getSchedule(String inFileName, String outFileName, int datastructure, int order, int backfilling);

    static {
        System.loadLibrary("ScheduleLibrary");
    }

}
