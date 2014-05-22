let rec a26 a1 =
  if a1 = [] then []
  else (a26 (List.tl a1))@[(List.hd a1)] in
    let rec a27 a2 a3 a4 =
      if a3 = [] then -1
      else if (String.compare (List.hd a3) a2)=0 then a4
      else (a27 a2 (List.tl a3) a4+1) in
    let rec a28 a5 a6 =
      if a5 = [] then [a6]
      else if List.hd a5 = a6 then a5
      else List.hd a5 :: a28 (List.tl a5) a6 in
    let rec a29 a7 a8 a10 =
      if a7 = [] then [a8]
      else if a10 = 0 then a8 :: a7
      else List.hd a7 :: (a29 (List.tl a7) a8 (a10-1)) in
    let rec a30 a9 a10 =
      if a10 = 0 then (List.tl a9)
      else List.hd a9 :: (a30 (List.tl a9) (a10-1)) in
    let rec a31 a20 a22 a21 a11 = begin
	let a12 = ref "" in
	let a13 = ref (-1) in
	for i = 0 to a21-1 do
	  let a14 = ref true in
	  for j=0 to a21-1 do
	    if (List.nth !(List.nth !a22 j) i) = 1 then begin
				                       a14 := false;
				                       ()
			                             end
	  done;
	  if !a14 && (List.length (List.fold_left (fun a15 a16 -> if (String.compare (List.nth a15 0) a16)=0 then a16::a15 else a15) [(List.nth !a20 i)] a11))=1 then begin
			                                                                                                                                             if !a13 = -1 || (String.compare !a12 (List.nth !a20 i)) > 0 then begin
				                                                                                                                                                                                                     a13 := i;
				                                                                                                                                                                                                     a12 := (List.nth !a20 i);
				                                                                                                                                                                                                     ()
			                                                                                                                                                                                                           end
		                                                                                                                                                   end
	done;
	(!a12, !a13)
      end in
    let a17 = ref [] in
    try
      while true do
        a17 := (read_line ()) :: !a17
      done
    with _ -> begin
	let a18 = (a26 !a17) in
	let a19 = (List.length a18) in
	let a20 = ref [] in
	a20 := List.fold_left a28 !a20 a18;
	let a21 = (List.length !a20) in
	let a22 = ref [] in
	for i = 0 to a21-1 do
	  let a23 = ref [] in
	  for j = 0 to a21-1 do
	    a23 := (a29 !a23 0 0);
	  done;
	  a22 := (a29 !a22 a23 0);
	done;
	for i = 0 to (a19-2)/2 do
	  let a24 = (a27 (List.nth a18 (i*2+1)) !a20 0) in
	  let a25 = (a27 (List.nth a18 (i*2)) !a20 0) in
	  (List.nth !a22 a24) := (a30 (!(List.nth !a22 a24)) a25);
	  (List.nth !a22 a24) := (a29 (!(List.nth !a22 a24)) 1 a25);
	done;
	let a11 = ref [] in
	try begin
	    for i=0 to a21-1 do
	      let a12, a13 = (a31 a20 a22 a21 !a11) in
	      ignore (a12 = (List.nth !a20 a13));
	      a11 := (!a11)@[a12];
	      for j=0 to a21-1 do
		(List.nth !a22 a13) := (a30 (!(List.nth !a22 a13)) j);
		(List.nth !a22 a13) := (a29 (!(List.nth !a22 a13)) 0 j);
	      done;
	    done;
	    List.iter print_endline !a11;
	  end
	with _ -> begin
	    print_endline "cycle";
	  end
      end
