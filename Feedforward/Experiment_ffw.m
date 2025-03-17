%% Pi
p = raspi('10.55.0.1','pi','sperte123')
%% Path
addpath('Model')
addpath('Reference')
%% Measurements
T_measure = 60;
measurements_reference = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error = measurements_reference(:,1);
acc = measurements_reference(:,2);
velocity = measurements_reference(:,3);
%% Checking requirements
% Tv constant = (42842-20959)/4000; So total stroke at constant v=22 is 120.3565
% We chose last period to remove transient effects
% File is measurements_reference_v2.mat
sample_i = 66412;
sample_f = 113555;
error_period = error(sample_i:sample_f);
acc_period = acc(sample_i:sample_f);
velocity_period = velocity(sample_i:sample_f);
constant_velocity_stroke = acc_period==0 & velocity_period ~= 0;
error_constant_velocity = error_period(constant_velocity_stroke);
plot(error_constant_velocity)
max_error = norm(error_constant_velocity, 'Inf')
rms_error = rms(error_constant_velocity)

%% Spectrum during feedforward
error_ffw = measurements_reference(:,1);
pwelch(error_ffw, hann(8000), 4000, 8000, 4000);
%% Feedforward
%% First measurements
T_measure = 60;
measurements_ff0 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff0 = measurements_ff0(:,1);
acc_ff0 = measurements_ff0(:,2);
velocity_ff0 = measurements_ff0(:,3);

%%
plot(error_ff0)
hold on
plot(acc_ff0)
hold off
%%
plot(error_ff0(45537:117538)) % One extra sample, wierd
%% Second measurement
T_measure = 60;
measurements_ff1 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff1 = measurements_ff1(:,1);
acc_ff1 = measurements_ff1(:,2);
velocity_ff1 = measurements_ff1(:,3);
%%
plot(error_ff1)
hold on
plot(acc_ff1)
hold off
%%
plot(error_ff0(45537:117538))
hold on
plot(error_ff1(45583:117584))
hold off
legend('no ff', 'kc')

%% Third measurement
T_measure = 60;
measurements_ff2 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff2 = measurements_ff2(:,1);
acc_ff2 = measurements_ff2(:,2);
velocity_ff2 = measurements_ff2(:,3);
%%
plot(error_ff2)
hold on
plot(acc_ff2)
hold off
%% Fourth measurement
T_measure = 60;
measurements_ff3 = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_ff3 = measurements_ff3(:,1);
acc_ff3 = measurements_ff3(:,2);
velocity_ff3 = measurements_ff3(:,3);
%%
plot(error_ff3)
hold on
plot(acc_ff3)
hold off
%%
plot(error_ff0(45537:117538))
hold on
plot(error_ff1(45583:117584))
hold on
plot(error_ff2(45408:117409))
hold on
plot(error_ff3(110332:182332))
hold off
legend('No FF', 'Coulomb', 'V', 'A')
% [-0.00038 -0.005 -0.00002]
%% Evaluating model
%% Measurements controller stab with FF
T_measure = 30;
measure_control_stab_yesFF = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_c1_yesFF = measure_control_stab_yesFF(:,1);
acc_c1_yesFF = measure_control_stab_yesFF(:,2);
velocity_c1_yesFF = measure_control_stab_yesFF(:,3);
%%
plot(acc_c1_yesFF)
error_period_c1_yesFF = error_c1_yesFF(32883:80026);
acc_period_c1_yesFF = acc_c1_yesFF(32883:80026);
velocity_period_c1_yesFF = velocity_c1_yesFF(32883:80026);
constant_velocity_stroke_c1_yesFF = acc_period_c1_yesFF==0 & velocity_period_c1_yesFF ~= 0;

error_constant_velocity_c1_yesFF = error_period_c1_yesFF(constant_velocity_stroke_c1_yesFF);
plot(error_constant_velocity_c1_yesFF)
max_error = norm(error_constant_velocity_c1_yesFF, 'Inf')
rms_error = rms(error_constant_velocity_c1_yesFF)
%% Comparison
plot(error_constant_velocity)
hold on
plot(error_constant_velocity_c1_yesFF)
hold off

%% Measuring controller FF with FF
T_measure = 30;
measure_control_FF_yesFF = SPERTE_Measure_And_Collect(p,3,Fs*T_measure,"Model_feedforward",1);
%%
error_c2_yesFF = measure_control_FF_yesFF(:,1);
acc_c2_yesFF = measure_control_FF_yesFF(:,2);
velocity_c2_yesFF = measure_control_FF_yesFF(:,3);
%%
plot(acc_c2_yesFF)
%%
error_period_c2_yesFF = error_c2_yesFF(25377:72520);
acc_period_c2_yesFF = acc_c2_yesFF(25377:72520);
velocity_period_c2_yesFF = velocity_c2_yesFF(25377:72520);
constant_velocity_stroke_c2_yesFF = acc_period_c2_yesFF==0 & velocity_period_c2_yesFF ~= 0;

error_constant_velocity_c2_yesFF = error_period_c2_yesFF(constant_velocity_stroke_c2_yesFF);
plot(error_constant_velocity_c2_yesFF)
max_error = norm(error_constant_velocity_c2_yesFF, 'Inf')
rms_error = rms(error_constant_velocity_c2_yesFF)
%% Comparison
plot(error_constant_velocity)
hold on
plot(error_constant_velocity_c1_yesFF)
hold on
plot(error_constant_velocity_c2_yesFF)
hold off
%%
[Error_PSD, f_PSD] = pwelch(error_constant_velocity_c2_yesFF, hann(8000),4000,8000,4000);
dataBode(Error_PSD,f_PSD)

%% DataBode
function dataBode(H,f)
    figure;
    subplot(2,1,1);
    semilogx(f,db(H))
    ylabel("|H| (db)")
    subplot(2,1,2);
    semilogx(f,angle(H)/pi*180)
    ylabel("\angle H (\circ)")
    xlabel('f (Hz)')
end