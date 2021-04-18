package model;

public class ScheduleModel {

    public native long makespan(final Schedule sched);

    public native long SumWjCj(Schedule sched);

    public native long SumWjFj(Schedule sched);

    public native long SumWjTj(Schedule sched);

    public ScheduleModel() {

    }

    static {
        System.loadLibrary("ScheduleLibrary");
    }
}
