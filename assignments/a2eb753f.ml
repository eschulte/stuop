let rec a16 a1 =
  match a1 with
    [] -> 0
  | hd::tl -> hd + (a16 tl);;
let a17 a2 =
  a16 (Array.to_list a2);;
let a3 = ref [] in
    let a4 = ref [] in
    let a5 = ref [] in
    try
      while true do
	let a6 = read_line () in
	a3 := a6 :: !a3;
	if (List.mem a6 !a4) != true
	then a4 := a6 :: !a4;
      done
    with _ -> begin
        a4 := List.sort
	        (fun a7 a8 ->
	         compare a8 a7)
	        !a4;
        a4 := List.rev !a4;
        let a9 = List.length !a4 in
	let a10 = Array.make_matrix a9 a9 0 in
	for i = 0 to (((List.length !a3) / 2) - 1) do
	  let a11 = (List.nth !a3 ((2 * i) + 1)) in
	  let a12 = List.nth !a3 (2 * i) in
	  for j = 0 to ((List.length !a4) - 1) do
	    if compare a12 (List.nth !a4 j) == 0
	    then for k = 0 to ((List.length !a4) -1) do
		   if compare a11 (List.nth !a4 k) == 0
		   then let a13 = Array.get a10 j in
			Array.set a13 k 1;
			()
		 done;
	  done;
	done;
	let a14 = ref [] in
	for i = 0 to ((List.length !a4) -1) do
	  if (a17(a10.(i)) == 0)
	  then a14 := i :: !a14;
	  ()
	done;
	while ((List.length !a14) > 0) do
	  let a15 = List.hd !a14 in
	  a14 := (List.tl !a14);
	  a5 := !a5 @ [a15];
	  for j = 0 to ((List.length !a4) - 1) do
	    if (a10.(j).(a15) == 1)
	    then (
	      Array.set a10.(j) a15 0;
	      if (a17(a10.(j)) == 0)
	      then (
		a14 := j :: !a14;
		a14 := List.sort
			 (fun a7 a8 ->
			  compare a8 a7)
			 !a14
	      );
	    );
	    ();
	  done;
	  ();
	done;
	a5 := List.rev !a5;
	if (List.length !a4) != (List.length !a5)
	then print_endline "cycle"
	else for i = 0 to ((List.length !a5) - 1) do
	       print_endline (List.nth !a4 (List.nth !a5 i));
	       ()
	     done;
      end
