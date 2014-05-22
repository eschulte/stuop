let a1 = ref [] in
    let a2 = ref [] in
    let a7 = ref [] in
    let rec a24 a3 a16 :bool = match a3 with
      | [] -> false
      | hd :: tl ->
	 if a16 = hd then true else (a24 tl a16) in
    let rec a25 a3 a16 :bool = match a3 with
      | [] -> false
      | hd :: tl -> let a21, a22 = hd in match a21 with
		                         | _ when a21 = a16 -> true
		                         | _ -> (a25 tl a16) in
    try
      let a4 = ref 0 in
      let a5 = ref "" in
      while true do
	let a6 = (read_line ()) in
	(if not (a24 !a1 a6) then (a1 := a6 :: !a1));
	(if not (a25 !a7 a6) then (a7 := (a6, 0) :: !a7););
	(if !a4 mod 2 = 0 then
	   (a5 := a6;
	    let rec incr a7 a19 a16 = match a7 with
	      | [] -> a19
	      | hd :: tl -> let a21, a22 = hd in match a21 with
						 | _ when a21 = a16 -> (a21, a22 + 1) :: (a19 @ tl)
						 | _ -> (incr tl (hd :: a19) a16) in
	    a7 := (incr !a7 [] !a5);)
	 else
	   (a2 := (a6, !a5) :: !a2);
	);
	a4 := !a4 + 1
      done
    with _ -> begin
	let a8 = List.fold_left (fun a19 a20 -> let a21, a22 = a20 in (if a22 = 0 then a21 :: a19 else a19)) [] !a7 in
	let rec a26 a9 a10 a11 a23 = let a12 = List.sort (fun a13 a14 -> (compare a13 a14)) a9 in match a12 with
		                                                                                  | [] -> a23
		                                                                                  | hd :: tl -> let a15 = (List.map (fun a16 -> let a17, a18 = a16 in
						                                                                                                (if (a24 a10 (hd, a17)) then
							                                                                                           (a17, a18 - 1)
						                                                                                                 else
							                                                                                           (a17, a18))) (List.fold_left (fun a19 a20 -> let a21, a22 = a20 in (if a22 = 0 then a19 else (a21, a22) :: a19)) [] a11)) in
			                                                                                        (a26 (tl @ (List.fold_left (fun a19 a20 -> let a21, a22 = a20 in (if a22 = 0 then a21 :: a19 else a19))) [] a15) a10 a15 (a23 @ [hd])) in
	let a23 = (a26 a8 !a2 !a7 []) in
	if (List.length a23) <> (List.length !a1) then
	  print_endline "cycle"
	else
	  List.iter print_endline a23;
      end
