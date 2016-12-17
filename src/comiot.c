/*
 * comiot.c
 *
 *  Created on: Dec 17, 2016
 *      Author: behema
 */

#include "network.h"
#include "region_layer.h"
#include "cost_layer.h"
#include "utils.h"
#include "parser.h"
#include "box.h"
#include "demo.h"
#include "option_list.h"

#ifdef OPENCV
#include "opencv2/highgui/highgui_c.h"
#endif
static int coco_ids[] = {1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20,21,22,23,24,25,27,28,31,32,33,34,35,36,37,38,39,40,41,42,43,44,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,67,70,72,73,74,75,76,77,78,79,80,81,82,84,85,86,87,88,89,90};

void run_comiot(int argc, char **argv){
	char *prefix = find_char_arg(argc, argv, "-prefix", 0);
	float thresh = find_float_arg(argc, argv, "-thresh", .24);
	int cam_index = find_int_arg(argc, argv, "-c", 0);
	int frame_skip = find_int_arg(argc, argv, "-s", 0);
	if(argc < 4){
		fprintf(stderr, "usage: %s %s [cfg] [weights (optional)]\n", argv[0], argv[1]);
		return;
	}
	char *gpu_list = find_char_arg(argc, argv, "-gpus", 0);
	int *gpus = 0;
	int gpu = 0;
	int ngpus = 0;
	if(gpu_list){
		printf("%s\n", gpu_list);
	    int len = strlen(gpu_list);
	    ngpus = 1;
	    int i;
	    for(i = 0; i < len; ++i){
	    	if (gpu_list[i] == ',') ++ngpus;
	    }
	    gpus = calloc(ngpus, sizeof(int));
	    for(i = 0; i < ngpus; ++i){
	    	gpus[i] = atoi(gpu_list);
	        gpu_list = strchr(gpu_list, ',')+1;
	    }
	} else {
		gpu = gpu_index;
	    gpus = &gpu;
	    ngpus = 1;
	}
	int clear = find_arg(argc, argv, "-clear");
	char *datacfg = argv[2];
	char *cfg = argv[3];
	char *weights = (argc > 4) ? argv[4] : 0;
	char *filename = (argc > 5) ? argv[5]: 0;

	list *options = read_data_cfg(datacfg);
	int classes = option_find_int(options, "classes", 20);
	char *name_list = option_find_str(options, "names", "data/names.list");
	char **names = get_labels(name_list);

	comiot_demo(cfg, weights, thresh, cam_index, filename, names, classes, frame_skip, prefix);
}


