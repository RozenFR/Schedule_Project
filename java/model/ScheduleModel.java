package model;

public class ScheduleModel {

    static {
        System.loadLibrary("schedule_library");
    }

    public native void getSchedule(String inFileName, String outFileName, int datastructure, int order, int backfilling);

}
