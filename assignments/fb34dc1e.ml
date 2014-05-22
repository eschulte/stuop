let a17() = begin
    let rec a18 a1 = function
      | [] -> []
      | h :: t -> if a1 = 0 then t else h :: a18 (a1-1) t
    in
    let a2 = ref [] in
    begin try
        while true do
          a2 := (read_line ()) :: !a2
        done
      with _ -> () end ;
    let rec a19 a3 a6 =
      match a6 with
      | hd :: snd :: tl -> (a19 ((snd, hd) :: a3) tl)
      | [] -> a3
      | _ -> a3
    in
    let a4 = ref (a19 [] !a2) in
    let rec a20 a5 a6 =
      match a6 with
      | [] -> a5
      | hd :: tl -> (
	try (
	  Hashtbl.replace a5 (fst(hd)) ((Hashtbl.find a5 (fst(hd))) + 1);
	  try (
	    Hashtbl.replace a5 (snd(hd)) ((Hashtbl.find a5 (snd(hd))));
	    a20 a5 tl
	  )
	  with Not_found -> (
	    Hashtbl.add a5 (snd(hd)) 0;
	    a20 a5 tl
	  );
	)
	with Not_found -> (
	  Hashtbl.add a5 (fst(hd)) 0;
	  a20 a5 a6
	);
      )
    in
    let a7 = ref (a20 (Hashtbl.create 2017) !a4) in
    let a8 = ref (Hashtbl.fold (fun a9 a10 a11 ->
	                        match a10 with
	                        | 0 -> a9 :: a11
	                        | _ -> a11
                               ) !a7 []) in
    let a12 = ref [] in
    while not (List.length !a8 = 0) do
      a8 := (List.sort
	       (fun a13 a14 -> compare a13 a14) !a8);
      let a15 = (List.nth !a8 0) in
      a8 := (a18 0 !a8);
      Hashtbl.remove !a7 a15;
      a12 := !a12 @ [a15];
      List.iter (fun a16 -> if snd(a16) = a15 then
		              Hashtbl.replace !a7 (fst(a16))
				              ((Hashtbl.find !a7 (fst(a16))) - 1)
	        ) !a4;
      Hashtbl.fold (fun a9 a10 a11 ->
		    if (a10 = 0 && not (List.mem (a9) !a8)) then
		      a8 := a9 :: !a8
	           ) !a7 ();
    done;
    if (Hashtbl.length !a7) > 0 then
      print_endline ("cycle")
    else
      List.iter print_endline !a12;
  end ;;
  a17() ;;
